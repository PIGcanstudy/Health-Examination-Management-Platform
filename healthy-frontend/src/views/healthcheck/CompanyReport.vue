<!-- 单位报告 -->
<template>
  <div>
    <el-container>
      <el-aside>
        <PeoplleList title="报告查询"></PeoplleList>
      </el-aside>
      <el-main>
        <div class="form">

          <Head name="报告信息">
            <el-button v-if="showChangeBtn" type="primary" @click="change">修改</el-button>
            <el-button v-if="showSaveBtn" type="primary" @click="save">保存</el-button>
          </Head>
          <div>
            <el-form id="myForm" :disabled="isDisabled" :model="formData" :inline="true">
              <el-form-item v-model="formData.num" label="报告编号">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="体检类型">
                <el-select v-model="formData.checkupType" placeholder="更多操作">
                  <el-option label="健康体检" value="type1"></el-option>
                  <el-option label="职业体检" value="type2"></el-option>
                  <el-option label="" value="type3"></el-option>
                </el-select>
              </el-form-item>
              <el-form-item label="体检单位">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="委托单位">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="报告日期">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="体检人数">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="体检项目">
                <el-input placeholder="请输入" clearable type="textarea" />
              </el-form-item>
              <el-form-item label="评论依据">
                <el-input placeholder="请输入" clearable type="textarea" />
              </el-form-item>
              <el-form-item label="体检结论与处理意见">
                <el-input placeholder="请输入" clearable type="textarea" />
              </el-form-item>
            </el-form>
          </div>
        </div>

        <div class="tables">

          <Head name="汇总表">
            <el-button type="primary">导出</el-button>
          </Head>
          <el-tabs v-model="activeName" @tab-click="handleClick" type="border-card">
            <el-tab-pane label="体检人员汇总表" name="first">
              <BaseDataList :useFixed="false" :tableData="dataOneRow" :tableColumnAttribute="dataOneColumn"></BaseDataList>
            </el-tab-pane>
            <el-tab-pane label="复查人员汇总表" name="second">
              <BaseDataList :useFixed="false"></BaseDataList>
            </el-tab-pane>
            <el-tab-pane label="复查结果汇总表" name="third">
              <BaseDataList :useFixed="false"></BaseDataList>
            </el-tab-pane>
          </el-tabs>
        </div>
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import PeoplleList from '@/components/peoplelist/PeopleList.vue'
import { ref } from 'vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import Head from '@/components/head/Head.vue'

const isDisabled = ref(true)
const showChangeBtn = ref(true)
const showSaveBtn = ref(false)
function change() {
  isDisabled.value = false
  showChangeBtn.value = false
  showSaveBtn.value = true
}

function save() {
  isDisabled.value = true
  showChangeBtn.value = true
  showSaveBtn.value = false
}


const formData = ref(
  {

  }
)

const dataOneColumn = [
  {
    prop: 'name',
    label: '单位名称'
  },
  {
    prop: 'credit',
    label: '信用代码'
  },
  {
    prop: 'examination',
    label: '体检类型'
  },
  {
    prop: 'address',
    label: '所属地区'
  },
  {
    prop: 'category',
    label: '行业类别'
  },
  {
    prop: 'etype',
    label: '经济类型'
  },
  {
    prop: 'scale',
    label: '企业规模'
  },
  {
    prop: 'contact',
    label: '联系人'
  },
  {
    prop: 'phone',
    label: '联系电话'
  }
]
// 每行的数据
const dataOneRow = [
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '习水宏旭纸箱有限公司',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '--',
    scale: '--',
    contact: '蔡徐坤',
    phone: '--'
  },
  {
    name: '四川峨边三丰冶金材料',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  }
]
</script>

<style lang="scss" scoped>
.head {
  font-weight: bold;
}

// .input {
//   --el-input-width: 400px;
// }
</style>
