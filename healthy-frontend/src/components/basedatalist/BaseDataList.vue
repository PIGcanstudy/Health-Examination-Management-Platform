<template>
  <div class="base_data_list">
    <el-card class="box-card">
      <template v-if="props?.useForm" #header>
        <!-- form表单 -->
        <el-form :model="formData" inline>
          <slot name="form"></slot>
        </el-form>
      </template>
      <div class="main">
        <!-- 功能栏 -->
        <slot name="operation"></slot>
        <!-- 多选清除栏 -->
        <slot name="hint"></slot>
        <!-- table表格 -->
        <el-table :data="props?.tableData" border @selection-change="handleSelectionChange">
          <!-- 多选列 -->
          <el-table-column type="selection"></el-table-column>
          <!-- 表格内容 -->
          <el-table-column v-for="item in props.tableColumnAttribute" :key="item" :prop="item.prop" :label="item.label" :width="item.width" :align="item.align" />
          <!-- 固定列 -->
          <el-table-column v-if="props.useFixed" fixed="right" label="操作" width="160">
            <template #default="{ row }">
              <el-button link type="primary" @click="props.handleEdit(row)">编辑</el-button>
              <el-button link type="primary" @click="props.handleDelete(row)">删除</el-button>
            </template>
          </el-table-column>
        </el-table>
        <!-- 分页 -->
        <template v-if="props.usePagination">
          <el-pagination
            v-model:current-page="props.paginationData.currentPage"
            v-model:page-size="props.paginationData.pageSize"
            layout="total,prev, pager, next, jumper, ->"
            :total="props.total"
            style="margin-top: 30px; justify-content: flex-end"
            @current-change="handleCurrentChange"
          />
        </template>
      </div>
    </el-card>
  </div>
</template>

<script setup>
import { watch, ref, defineEmits } from 'vue'
const props = defineProps({
  // 是否使用Form表单
  useForm: {
    type: Boolean,
    default: false
  },
  // form表单数据
  formData: {
    type: Object,
    require: true
  },
  // 表格数据
  tableData: {
    type: Array,
    require: true
  },
  // 表格列属性
  tableColumnAttribute: {
    type: Array,
    require: true
  },
  // 是否使用固定列
  useFixed: {
    type: Boolean,
    default: true
  },
  // 分页参数
  paginationData: {
    type: Object,
    default: () => {
      return 5
    }
  },
  // 表格的数据数量
  total: {
    type: Number,
    require: true
  },
  // 是否使用分页器
  usePagination: {
    type: Boolean,
    default: true
  },
  // 编辑方法
  handleEdit: Function,
  handleDelete: Function
})
const emits = defineEmits(['updateTableData', 'update:modelValue', 'update-table-data', 'update-selected-rows'])
// 实现 form表单v-model 逻辑
watch(
  () => props.formData,
  (newVal) => {
    emits('update:modelValue', newVal)
  },
  { deep: true }
)
const rows = ref()
const handleSelectionChange = (selectRows) => {
  rows.value = selectRows
  emits('update-selected-rows', selectRows)
}
defineExpose({
  rows
})
const handleCurrentChange = (currentPage) => {
  // console.log(currentPage)
  console.log(props.paginationData.pageSize)
  emits('update-table-data', props.paginationData.pageSize, currentPage)
}
</script>

<style lang="scss" scoped></style>
