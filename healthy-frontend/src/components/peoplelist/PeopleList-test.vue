<template>
  <div class="left-side">
    <!-- 列表名称区域 -->
    <el-card class="top">
      <div class="list-name">
        <span>人员列表</span>
      </div>
    </el-card>

    <!-- 主体部分 -->
    <el-card class="body" shadow="hover">
      <!-- 表单控件区域 -->
      <div class="form">
        <el-form ref="ruleFormRef" :model="form">
          <template v-for="item in formConfig.formItems" :key="item.name">
            <el-form-item :prop="item.name">
              <template v-if="item.type === 'select' || item.type === 'slider'">
                <el-radio-group v-model="form[item.name]" style="margin-right: auto">
                  <el-radio label="已检" />
                  <el-radio label="未检" />
                </el-radio-group>
                <el-switch v-model="slider" inline-prompt active-text="复查" inactive-text="非复"></el-switch>
              </template>

              <template v-else-if="item.type === 'datepicker'">
                <el-row clearable>
                  <el-date-picker v-model="form" style="width: 49%" type="date" placeholder="开始时间" />
                  <span style="width: 2%">~</span>
                  <el-date-picker v-model="form.endDate" style="width: 49%" type="date" placeholder="结束时间" />
                </el-row>
              </template>

              <div class="input-area">
                <el-form-item>
                  <el-input v-model="form.name" :placeholder="item.placeholder" clearable />
                </el-form-item>
                <!-- 点击按钮折叠区域 -->
                <div v-show="isShowInput">
                  <el-form-item>
                    <el-input v-model="form.serialNumber" placeholder="请输入体检编号" clearable />
                  </el-form-item>
                  <el-form-item>
                    <el-input v-model="form.workplace" placeholder="请输入单位名称" clearable></el-input>
                  </el-form-item>
                </div>
              </div>

              <el-button type="primary" @click="onSubmit">查询</el-button>
              <el-button plain @click="resetForm">重置</el-button>
              <div>
                <el-button type="text" style="margin-left: 14px" @click="toggleCollapse"
                  >{{ isShowInput ? '收起' : '展开' }}
                  <el-icon v-show="isShowInput === true"><ArrowUp /></el-icon>
                  <el-icon v-show="isShowInput === false"><ArrowDown /></el-icon>
                </el-button>
              </div>
            </el-form-item>
          </template>
        </el-form>
      </div>

      <!-- 表格数据区域 -->
      <div class="table">
        <el-table
          ref="tableRef"
          v-loading="loading"
          height="300"
          :data="tableData"
          :show-header="false"
          highlight-current-row
          fit
          @select="select"
          @selection-change="handleSelectionChange"
          @row-click="selectClick"
        >
          <el-table-column type="selection" width="40%"></el-table-column>
          <el-table-column v-for="(item, index) in tableTitle" :key="index" :prop="item.prop" label="item.label"> </el-table-column>

          <template #default="{ row }" v-if="item.useTag">
            <el-tag :type="row[item.prop].tagType">{{ row[item.prop].value }}</el-tag>
          </template>

          <el-table-column>
            <el-tag type="success" style="margin-right: 4px">健</el-tag>
            <el-tag type="danger">零</el-tag>
          </el-table-column>
        </el-table>
      </div>

      <!-- 分页区域 -->
      <el-pagination
        v-model:current-page="currentPage"
        v-model:page-size="pageSize"
        layout="prev, jumper, pager, next, "
        :total="50"
        :small="small"
        pager-count="5"
        style="margin-top: 30px"
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
      />
    </el-card>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { ArrowUp, ArrowDown } from '@element-plus/icons-vue'

// 滑块开关逻辑
const slider = ref(true)

// 表单验证逻辑
const form = ref({
  name: '',
  serialNumber: '',
  workplace: '',
  startDate: '',
  endDate: '',
  checkbox: ''
})
// 封装表单: 表单配置项
const formConfig = {
  formItems: [
    {
      type: 'select',
      name: 'select',
      options: [
        {
          label: '已检',
          value: 1
        },
        {
          label: '未检',
          value: 0
        }
      ]
    },
    {
      type: 'slider',
      name: 'slider',
      options: [
        {
          label: '复查',
          value: 1
        },
        {
          label: '非复',
          value: 0
        }
      ]
    },
    {
      type: 'datepicker',
      name: 'datepicker',
      Option: {
        startPlaceholder: '开始日期',
        endPlaceholder: '结束日期',
        type: 'daterange'
      }
    },
    {
      type: 'input',
      name: 'user',
      placeholder: '请输入姓名'
    }
  ]
}

// 提交表单查询逻辑
const onSubmit = () => {
  console.log('submit')
}
// 重置表单逻辑
const resetForm = () => {
  console.log('reset')
}
// 点击按钮折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}

// 页面加载逻辑
const loading = ref(false)

// 表格数据存放区域
const tableTitle = [
  { prop: 'name', label: '姓名' },
  { prop: 'gender', label: '性别' },
  { prop: 'age', label: '年龄' },
  { prop: 'tag', label: '状态' }
]
const tableData = [
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '健'
  },
  {
    name: '王勇',
    gender: '男',
    age: '26',
    tag: '团'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  }
]

const tableRef = ref()
const multipleSelection = ref([])
const handleSelectionChange = (val) => {
  multipleSelection.value = val
}
const select = (selection, row) => {
  // 清除 所有勾选项
  tableRef.value.clearSelection()
  // 当表格数据都没有被勾选的时候 就返回
  // 主要用于将当前勾选的表格状态清除
  if (selection.length === 0) return
  tableRef.value.toggleRowSelection(row, true)
}
// 控制单选——table选择项发生变化时
const selectClick = (row) => {
  const selectData = multipleSelection.value
  tableRef.value.clearSelection()
  if (selectData.length === 1) {
    console.log('获取该行数据')

    selectData.forEach((item) => {
      // 判断 如果当前的一行被勾选, 再次点击的时候就会取消选中
      if (item === row) {
        tableRef.value.toggleRowSelection(row, false)
      }
      // 不然就让当前的一行勾选
      else {
        tableRef.value.toggleRowSelection(row, true)
      }
    })
  } else {
    tableRef.value.toggleRowSelection(row, true)
  }
}

// 分页逻辑
const currentPage = ref(1)
const handleSizeChange = (size) => {
  console.log('当前每页条数', size)
}
const handleCurrentChange = (page) => {
  console.log('页码发生变化', page)
}

// v-shoe/v-if测试区域
</script>

<style lang="scss" scoped>
.left-side {
  height: 750px;
  width: 24%; //缩小到左边应该是24%
  margin-bottom: 0;
}

.top {
  text-align: center;
  background-color: rgb(240, 250, 255);

  span {
    color: rgb(81, 90, 110);
    font-weight: 550;
  }
}

.body {
  height: 100%;
  display: flex;
  flex-direction: column;
}
</style>
