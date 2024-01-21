<template>
  <div class="base_data_list">
    <el-card class="box-card">
      <template #header>
        <!-- form表单 -->
        <el-form v-if="props?.useForm" :model="formData" inline>
          <slot name="form"></slot>
        </el-form>
      </template>
      <div class="main">
        <!-- 功能栏 -->
        <slot name="operation"></slot>
        <!-- 多选清除栏 -->
        <slot name="hint"></slot>
        <!-- table表格 -->
        <el-table :data="props?.tableData" border>
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
            v-model:current-page="paginationData.currentPage"
            v-model:page-size="paginationData.pageSize"
            :page-sizes="props.pageSizes"
            layout="prev, pager, next, jumper, ->"
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
const rows = ref()
const props = defineProps({
  // 是否使用Form表单
  useForm: Boolean,
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
  // 表格每页的数据容量
  pageSizes: {
    type: Array,
    default: () => {
      return [5, 10, 15, 20]
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
const emits = defineEmits(['updateTableData', 'update:modelValue'])
// 实现 form表单v-model 逻辑
watch(
  () => props.formData,
  (newVal) => {
    emits('update:modelValue', newVal)
  },
  { deep: true }
)
// 分页
const paginationData = ref({
  currentPage: 1,
  pageSize: props.pageSizes ? props.pageSizes[0] : 5
})
const handleCurrentChange = (page) => {
  console.log('页码变化了' + page)
  paginationData.value.currentPage = page
  emits('updateTableData', paginationData.value.pageSize, page)
}
defineExpose({
  // 暴露出被选行
  rows
})
</script>

<style lang="scss" scoped></style>
